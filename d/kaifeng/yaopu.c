// /kaifeng/yaopu.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ�
�ٸ�С������ɢ�������ġ���ҽƽһָ���ڲ輸�Զ��Ժ��Ų裬��Ҳ��
����һ�ۡ�
LONG );
	set("objects", ([
		"/kungfu/class/heimuya/ping" : 1,
	]));
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"road1",
	]));
	setup();
	replace_program(ROOM);
}
