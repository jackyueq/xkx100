// Room: /d/5lt/yuchang.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "����ԡ��");
	set("long", @LONG
����һ���ǳ��ɾ��ĺ���ԡ����ÿ���ļ�����ͱ��ȫ�������ֵĵ�
��������������Ǳˮ���������㡢���˺���Ӿ�����ߵ���ͷ(pier)
�����Կ���һ�Һ�����ͧ��
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"east"  : __DIR__"haitan",
	]));
	set("objects",  ([
		__DIR__"npc/sunray": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -205);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}