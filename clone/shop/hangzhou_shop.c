// /clone/shop/hangzhou_shop.c
// Last modified by winder 2003.10.20
inherit SHOP;

void create()
{
	set("short", "����ի");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/hangzhou/majiu",
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
����ի�����ɺ��ݳǵ����ֺţ���ν���������������պ���������
�ǽ������һ����ҵ���Ҳ�����⡣����������ȴ����һ�������
�Ѻܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
����ի�����ɺ��ݳǵ����ֺţ���ν���������������պ���������
�ǽ������һ����ҵ���Ҳ�����⡣����װ��õ��ž��£��������
��������к��ſ��ˡ�
LONG);
        return;
}

