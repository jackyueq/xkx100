// /clone/shop/dali_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "������");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/dali/majiu",
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
�����Ǵ�����������������ֺţ���������װ�޵��൱ʮ��������
���ڵ���͸�Ŵ����ϵ�ζ������������Ļ�����ȴ����һ���������
���ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
�����Ǵ�����������������ֺţ���������װ�޵��൱ʮ��������
���ڵ���͸�Ŵ����ϵ�ζ����������Ļ�����к��ſ��ˣ�æ����ͷ��
����
LONG);
        return;
}

