//room: liangong.c

inherit ROOM;

void create()
{
	set("short","Ϸ���");
	set("long",@LONG
���������չ����������ĵط����м�������Ů������ר�����µ���
�䣬�м����ֳ���,�ڻ������,���鶯�����紩������һ�㣬�㲻
���������ۣ�����������ڵ��ϵ������Ͽ���������
LONG );
	set("exits",([
		"west" : __DIR__"changl4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5
	]));
	set("coor/x", -50970);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}