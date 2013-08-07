// Room: /d/suzhou/dongmen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻų����õ����ݶ����ţ��������Ϸ����š����š����������
�֣���ǽ�����ż��Źٸ���ʾ(gaoshi)�����Źٱ��Ǿ����ע���Ź���
���ˣ������С��Ϊ�һ����ֱ����ʯ���������������죬����
�ǳ��
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : "/d/jiaxing/jnroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 900);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n����\n";
}
