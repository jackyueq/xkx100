// Room: /d/chengdu/wangjianglou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long",@LONG
����������¥�ϣ���ĿԶ���������ɶ������������۵͡�ֻ������
����������ƵĻ���ȫ�ǣ�̫�����ں��棬�������Ӱ�Ĺ����Աߵ�
���������дУ�������Ҳ��ø�������������¥��ǽ�Ͽ���ǰ������ī
�����µ�ʫ�䡣
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"down" : __DIR__"wangjianglou1",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);       
}


