// Last Modified by Sir on May. 22 2001
//Room: byahoudian.c �����ֺ��

inherit ROOM;
void do_chat();

void create()
{
	set("short","�����ֺ��");
	set("long",@LONG
��ɽ�����ֵĺ��Ǻ�ɽ�������˵ľ��������﹩��һ��������
�������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š�
LONG);
	set("no_clean_up", 0);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"changlang",	     
	]));
	set("coor/x", 40);
	set("coor/y", 3230);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
