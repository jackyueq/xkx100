// Room: /d/yueyang/longwangmiao.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������¯ɽ�ϡ���¯ɽԭ������ɽ�����ζ�������ɽΪ��֮
ʤ�أ�ɽ�Ͻ������������Ƿ������ܵ�ɽ���ݣ�ֻ�������ڼ���ɽ
�£���ɽ���ݣ�������ƽ���������쳤�ؾã�ˮʯ�ಫ������ɽҲ��
Խ��ԽС�ˣ�����ع�㣬ɽ��������¯�������־������㣬���Ծͳ�Ϊ
��¯ɽ�ˡ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"xianglushan",
	]));
	set("coor/x", -1790);
	set("coor/y", 2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
