// Room: /d/quanzhou/weiyuanlou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "��Զ¥");
	set("long", @LONG
����Ȫ�ݵı��ų�¥����ʯ��������¥̨����쳣��Ρ������Ĺ�
�γ����Ϸ������š�Ȫ�ݡ�����������֡���ǽ������һ��Ȫ�ݹٸ���
ʾ(gaoshi)�����˴��ž��Ǳ���������᫵���Դɽ���ˡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"northroad3",
		"north" : __DIR__"shanlu6",
	]));
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
        ]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1850);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n��������\nʩ��\n";
}
