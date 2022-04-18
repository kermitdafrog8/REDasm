#include "listingtextview.h"
#include "../../../themeprovider.h"
#include "../../../redasmsettings.h"

ListingTextView::ListingTextView(const RDContextPtr& ctx, QWidget* parent): QSplitter(Qt::Horizontal, parent), m_context(ctx)
{
    this->setStyleSheet("QSplitter::handle { background-color: " + THEME_VALUE_COLOR(Theme_Seek) + "; }");

    m_textwidget = new ListingTextWidget(this);
    m_textwidget->setFont(REDasmSettings::font());
    m_textwidget->setContext(ctx);

    m_columnview = new ListingPathWidget(this);
    m_columnview->setFont(m_textwidget->font()); // Apply same font
    m_columnview->linkTo(m_textwidget);

    this->addWidget(m_columnview);
    this->addWidget(m_textwidget);

    this->setStretchFactor(0, 2);
    this->setStretchFactor(1, 10);
    this->setHandleWidth(4);
}

ListingPathWidget *ListingTextView::columnWidget() { return m_columnview; }
ListingTextWidget *ListingTextView::textWidget() { return m_textwidget; }
void ListingTextView::copy() const { return m_textwidget->copy(); }
void ListingTextView::goBack() { return m_textwidget->goBack(); }
void ListingTextView::goForward() { return m_textwidget->goForward(); }
bool ListingTextView::goTo(rd_address address) { return m_textwidget->goTo(address); }
bool ListingTextView::seek(rd_address address) { return m_textwidget->seek(address); }
bool ListingTextView::hasSelection() const { return m_textwidget->hasSelection(); }
bool ListingTextView::canGoBack() const { return m_textwidget->canGoBack(); }
bool ListingTextView::canGoForward() const {  return m_textwidget->canGoForward(); }
QString ListingTextView::currentLabel(rd_address* address) const { return m_textwidget->currentLabel(address); }
rd_address ListingTextView::currentAddress() const { return m_textwidget->currentAddress(); }
SurfaceQt* ListingTextView::surface() const { return m_textwidget->surface(); }
QString ListingTextView::currentWord() const { return m_textwidget->currentWord(); }
const RDContextPtr& ListingTextView::context() const { return m_context; }
QWidget* ListingTextView::widget() { return this; }
