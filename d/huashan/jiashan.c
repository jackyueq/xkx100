// jiashan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","��ɽС��");
	set("long",@LONG
������һ��С԰�ӣ���ͷ�и�С���������ܲ��м�ɽ��������԰��
��������ʱ��ˮ����Ϫ���У�����ˮ���������������̰��ö���ˮ��
������̧ͷ������ֻ��Զ����ɽ���죬�������֣��꾰��Ȥ���
LONG);
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/shengdi" : random(2),
	]));
	set("outdoors", "huashan");
	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
