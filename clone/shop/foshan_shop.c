// /clone/shop/foshan_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "�캣¥");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
		"down" : "/d/foshan/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
�캣¥�Ƿ�ɽ���������ĵ��̣��������������֮ʿ����¥����װ
�κ��ţ����к���֮������������Ļ�����ȴ����һ��������Ѿ���
��û���������ˡ�
LONG);
	else
		set("long", @LONG
�캣¥�Ƿ�ɽ���������ĵ��̣��������������֮ʿ����¥����װ
�κ��ţ����к���֮����������������������ϰ����˸�ʽ��������
����Ŀ�Ļ��
LONG);
        return;
}

