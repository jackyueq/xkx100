// Room: /d/qilian/datongling.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "��ͨ��");
	set("long", @LONG
������Ǵ�ͨ�룬Ϊ����������ɽ���Ľ�Ҫ֮�����ɼ�ɽ��Ұ��
������䣬���Ŵ˵�ʢ����֥����������ý����ֽŲ��á�
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"zhutishan",
		"southeast" : __DIR__"bulangpo2",
		"westup"    : __DIR__"niaojutai",
	]));
	set("coor/x", -10000);
	set("coor/y", 3000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}