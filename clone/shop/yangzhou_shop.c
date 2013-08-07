// /clone/shop/yangzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "������");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/city/majiu",
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
���������ݳ����������ĵ��̣���������װ�޵��൱�������£���
��ʮ�����ݷ����󷽵����ɡ���������Ļ�����ȴ����һ���������
���ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
���������ݳ��������ֵĵ��̣���������������������Ϣ������װ
�޵þ������£��Գ�ʮ�����ݷ����󷽵����ɡ�������Ļ�����к���
���ˣ�æ����ͷ�󺹡�
LONG);
        return;
}

