// Room: /d/quanzhou/diaoqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "���ŵ���");
	set("long", @LONG
����Ȫ�������һ�����ţ��Ӱ��Ž��Ӷ����ĳ�¥��������������
��άϵ���ճ����µ��ţ�������𡣳�¥ǽ�����Źٸ���ʾ(gaoshi)��
�������ű�����ʯ�ڣ����������˳�û��û�»��Ǳ���ǵĺá�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
        ]));
	set("exits", ([
		"west" : __DIR__"luanshigang",
		"east" : __DIR__"xinmenji",
	]));
	set("coor/x", 1830);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n��������\nʩ��\n";
}
