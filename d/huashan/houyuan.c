// houyuan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","��Ժ");
	set("long",@LONG
�����ǻ�ɽ�ɵĺ�Ժ�������ǻ�ɽ���ӵľ��Һ�����������ɽ����
����ɽ�����������վ��������������¡���������һ��С��Ժ���м�ɽ
С�أ���ɫ���ˣ����н�����԰����ɫ��
LONG);
	set("exits",([
		"northeast"  : __DIR__"garden",
		"west"       : __DIR__"jiashan",
		"east"       : __DIR__"xuanya",
	]));
	set("objects",([
		__DIR__"npc/shu-qi": 1,
	]));
	set("outdoors", "huashan");
	set("coor/x", -880);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
