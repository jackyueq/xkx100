// /clone/shop/quanzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "������");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/quanzhou/majiu",
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
������Ȫ�ݳ����һ�ҵ��̡�Ȫ�ݳ���С����Դɽȴ��Ϊ��������
���̺�ľ�񴰷�����ȥ������Ȫ�ݹų����������Ľֵ������۵ס�����
����Ļ�����ȴ����һ��������Ѿ��ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
������Ȫ�ݳ����һ�ҵ��̡�Ȫ�ݳ���С����Դɽȴ��Ϊ��������
���̺�ľ�񴰷�����ȥ������Ȫ�ݹų����������Ľֵ������۵ס�����
��Ļ�����к��ſ��ˣ�æ����ͷ�󺹡�
LONG);
        return;
}

