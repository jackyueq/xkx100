// /clone/shop/yili_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "ţ����");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/xingxiu/majiu",
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
������ţ����Ķ����̸���֡�¥��װ��÷ǳ����ž��£�������
�ݳ���һ������ľ�̵أ����ŵ񴰣��������й���һ���ٺ�ͼ��������
����ȴ����һ��������Ѻܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
������ţ����Ķ����̸���֡�¥��װ��÷ǳ����ž��£�������
�ݳ���һ������ľ�̵أ����ŵ񴰣��������й���һ���ٺ�ͼ����ʱ��
�û����æ��æ�£��к��ſ��ˡ�
LONG);
        return;
}

