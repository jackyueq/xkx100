// Room: /d/lingxiao/jianyuting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����С��");
	set("long", @LONG
������������ǵļ�����ڡ������ǵļ���ר��������Ѻ�����Ź�
�ĵ��ӣ�һЩ���е����鷸�ƣ���������֮ͽҲ˳����Ѻ�ڴˡ�������
��һ�����ɣ������Ź�ɭ�ϣ���Ҳ���з����ߣ��������������صأ���
����Ҳ���ܡ�
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("exits", ([
		"west" : __DIR__"iceroad3",
		"down" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/yan" : 1,
		__DIR__"npc/dizi" : 3,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup(); 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["master_id"] != "bai zizai") &&
		dir == "down" &&
		objectp(present("yan wanpeng", environment(me))))
		return notify_fail("���������һ�����˴��˱��ɽ��أ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
	return ::valid_leave(me, dir);
}

