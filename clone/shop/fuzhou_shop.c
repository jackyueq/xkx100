// /clone/shop/fuzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "�۴�԰");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/fuzhou/majiu",
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
�۴�԰�Ǹ��ݳ��������ĵ��̣��������й��ŵ�һ���Ҷ���ϴ�
�顸��ɽ�۴����ĸ����֣��������ش󿪡���������Ļ�����ȴ����һ
��������Ѿ��ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
�۴�԰�Ǹ��ݳ��������ĵ��̣��������й��ŵ�һ���Ҷ���ϴ�
�顸��ɽ�۴����ĸ����֣��������ش󿪡�������������������ϰ�
���˸�ʽ������������Ŀ�Ļ��
LONG);
        return;
}

