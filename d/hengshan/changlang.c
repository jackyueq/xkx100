// Last Modified by Sir on May. 22 2001
//Room: changlang.c ����

inherit ROOM;
void do_chat();

void create()
{
	set("short","����");
	set("long",@LONG
ͨ����ɽ�����ֵĺ���һ�����ȡ����������Ǻ�ɽ�������˵ľ�
�����ϱ��Ǻ�ɽ�ɰ����֡�
LONG);
	set("no_clean_up", 0);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"baiyunan", 
		"north" : __DIR__"byahoudian",
	]));
	set("coor/x", 40);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
