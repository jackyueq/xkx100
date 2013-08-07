// beijing_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "�����");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/beijing/majiu",
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
������Ǳ�������������������飬��������������������Ϣ����
������֮�������󷽵����ɡ���������Ļ�����ȴ����һ���������
���ܾ�û���������ˡ�
LONG);
	else
		set("long", @LONG
������Ǳ�������������������飬��������������������Ϣ����
������֮�������󷽵����ɡ���������������ϰ����˸�ʽ��������
����Ŀ�Ļ��
LONG);
        return;
}
