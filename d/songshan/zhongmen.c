// Room: /d/songshan/zhongmen.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ�����Ժͨ����ͥ�����ţ��ź����磬����ͭ������������
���񾭶�����꣬���а��䣬������ɫ���£���������ɽ���½�������
�ġ�������ʿ���˾͸û�ͷ�ˡ�
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"south" : __DIR__"chanyuan",
		"north" : __DIR__"huimengtang",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/yao": 1,
	]));
	set("coor/x", -20);
	set("coor/y", 880);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if ( me->query("combat_exp") < 1000 ) return 1;
	if ( (!myfam || (myfam["family_name"] != "��ɽ��")) &&
		(dir == "north") &&
		objectp(present("yao hou", environment(me))))
		return notify_fail("�ֺ�һ̧����ס���㣺����ɽ���ӣ�����ֹ���ɡ�\n");
	else return 1;
}

