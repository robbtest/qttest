#### 类介绍

QBoxLayout         盒子布局

QVBoxLayout       纵向布局

QHBoxLayout      横向布局

QGridLayout        栅格布局

QFormLayout      表单布局

QStackedLayout 切换布局

#### 关系图

```

QObject            QLayout    QBoxLayout        QVBoxLayout   

QLayoutItem                                     QHBoxLayout

​                             QGridLayout   

​                             QFormLayout

​                             QStackedLayout 

```

#### QBoxLayout   QVBoxLayout   QHBoxLayout                       

- setSpacing

- setContentsMargins
- addItem
- addWidget
- addLayout

#### QGridLayout

- setHorizontalSpacing
- setVerticalSpacing
- setContentsMargins
- addWidget

#### QFormLayout

- setSpacing
- setContentsMargins
- setWidget
- addRow
- insertRow

#### 例子

QBoxLayout

```c++
// create QHBoxLayout
QHBoxLayout* pMainHLayout = new QHBoxLayout();
pMainHLayout->setSpacing(0);
pMainHLayout->setContentsMargins(0, 0, 0, 0);
// add QSpacerItem to QHBoxLayout
QSpacerItem* pSpace = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
pMainHLayout->addItem(pSpace);
// add QPushButton to QHBoxLayout
QPushButton* pBtn = new QPushButton(this);
pBtn->setText("T");
pMainHLayout->addWidget(pBtn);
// add QVBoxLayout to QHBoxLayout
QVBoxLayout* pVLayout = new QVBoxLayout(this);
pMainHLayout->addLayout(pVLayout);
```

QGridLayout

```c++
// 构建控件 头像、用户名、密码输入框等
QLabel*    pImageLabel         = new QLabel(this);
QLineEdit* pUserLineEdit       = new QLineEdit(this);
QLineEdit* pPasswordLineEdit   = new QLineEdit(this);
QCheckBox* pRememberCheckBox   = new QCheckBox(this);
QCheckBox* pAutoLoginCheckBox  = new QCheckBox(this);
QPushButton* pLoginButton      = new QPushButton(this);
QPushButton* pRegisterButton   = new QPushButton(this);
QPushButton* pForgotButton     = new QPushButton(this);

QGridLayout *pLayout = new QGridLayout();
pLayout->setHorizontalSpacing(10);
pLayout->setVerticalSpacing(10);
pLayout->setContentsMargins(10, 10, 10, 10);

pLayout->addWidget(pImageLabel, 0, 0, 3, 1);      // 头像 第0行，第0列开始，占3行1列
pLayout->addWidget(pUserLineEdit, 0, 1, 1, 2);    // 用户名输入框 第0行，第1列开始，占1行2列
pLayout->addWidget(pRegisterButton, 0, 4);
pLayout->addWidget(pPasswordLineEdit, 1, 1, 1, 2);// 密码输入框 第1行，第1列开始，占1行2列
pLayout->addWidget(pForgotButton, 1, 4);
// 记住密码 第2行，第1列开始，占1行1列 水平居左 垂直居中
pLayout->addWidget(pRememberCheckBox, 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);
// 自动登录 第2行，第2列开始，占1行1列 水平居右 垂直居中
pLayout->addWidget(pAutoLoginCheckBox, 2, 2, 1, 1, Qt::AlignRight | Qt::AlignVCenter);
// 登录按钮 第3行，第1列开始，占1行2列
pLayout->addWidget(pLoginButton, 3, 1, 1, 2);
```

QFormLayout

```C++
QFormLayout* pFormLayout = new QFormLayout(formLayoutWidget);
pFormLayout->setSpacing(6);
pFormLayout->setContentsMargins(0, 0, 0, 0);
// add one item
QLabel*    pNameLabel    = new QLabel();
QLineEdit* pNameLineEdit = new QLineEdit();
pFormLayout->setWidget(0, QFormLayout::LabelRole, pNameLabel);
pFormLayout->setWidget(0, QFormLayout::FieldRole, pNameLineEdit);
// or do like this
QLabel*    pNameLabel    = new QLabel();
QLineEdit* pNameLineEdit = new QLineEdit();
pFormLayout->addRow(pNameLabel, pNameLineEdit);
// or do simply
QLineEdit* pNameLineEdit = new QLineEdit();
pFormLayout->addRow("name", pNameLineEdit);
```
