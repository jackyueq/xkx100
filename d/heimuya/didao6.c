// Room: /d/heimuya/didao6.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ص���ͷ");
	set("long", @LONG
�����ǰ��һ������ǰ���Ǳ��ж��죬ǰ������������԰����֪��
ʲô�ط���
LONG );
	set("exits",([
		"north"     : __DIR__"xiaohuayuan",
		"northdown" : __DIR__"didao4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}