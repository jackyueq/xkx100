// /clone/shop/yanping_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "˫Ϫ¥");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
		"down" : "/d/yanping/majiu",
	]));
	set("objects", ([
		__DIR__"waiter" : 1,
	]));
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
��������ƽ�����������ĵ��̣���������װ�޵��൱�������£�¥
��ƾ���������Ǹ��˫Ϫ�����ĺ�ȥ������������Ļ�����ȴ����һ�
�������Ѿ��ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
��������ƽ���������ֵĵ��̣���������װ�޵��൱�������£�¥
��ƾ���������Ǹ��˫Ϫ�����ĺ�ȥ����������Ļ�����к��ſ��ˣ�
æ����ͷ�󺹡�
LONG);
	return;
}

