// /kaifeng/cangjing1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ؾ�¥");
	set("long", @LONG
�ؾ�¥��һ������С¥����¥�ж��Ƿ�Ҿ��䣬����ϡ�ٵĶ���̴
ľ��ʢ���ˡ��ղ���¥�ϣ�����ר��ְ˾�������ۿ�ȥ�������Ǹߵ͵�
��ܣ�
LONG);
	set("objects", ([
		__DIR__"npc/zhifa" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"cangjing2",
		"west" : __DIR__"houyuan",
		"east" : __DIR__"xiaoyuan",
	]));

	setup();
	replace_program(ROOM);
}
