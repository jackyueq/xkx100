// Room: /d/huangshan/wenquan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
��ɽ��Ȫ�ų���Ȫ�������ơ����Ʒ��²�̫������ʩ¯���Գ�������
������ҽҩ�����������¡���Ϊ�����ӿ����ɫȪˮ����Ϊ��ɰ������
�ֳ���ɰȪ������ɽ���ڴ˽�®�ᣬ�����ף�������ԡ���޲������
������Ȫ���ϱ��Ǵȹ�󣬱���ԶԶ�ɼ�����ͤ��
LONG
	);
	set("exits", ([ 
		"northup"   : __DIR__"ciguang", 
		"eastup"    : __DIR__"guanpu",
		"southdown" : __DIR__"shanmen", 
	]));
	set("objects", ([
		__DIR__"obj/tangquan" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
