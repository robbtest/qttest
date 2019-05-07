### 类关系

QListView
 - setItemDelegate
 - setModel
 
QStyledItemDelegate - Inherit
 - paint
 - sizeHint
 
QStandardItemModel
 - appendRow 
QStandardItem
 - setData
 
 ### 数据显示关系
 QStandardItem - setData  ->  QStyledItemDelegate - paint
