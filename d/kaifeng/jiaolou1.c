// /kaifeng/jiaolou1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��¥�ǽ��ڳ�ǽ֮�ϣ����ڱ��������Ĵ�����ֻ��¥�Ķ��˹���һ
յ�������Ӵ�Զ����Զ��ɽˮ̨ͤ��һһ��Ŀ��������ȥ��������֡�
·�����������˲��ϡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"zhuque",
		"westdown" : __DIR__"wroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
