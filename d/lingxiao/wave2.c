// Room: /d/lingxiao/wave2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG 
��������һ��������������������������Ȼ����͸�����ڿ�������
������Ⱥɽ��ԭ���������ǽ���������ϵı��㣬�¹�����������յ�
�������ԣ������������������𡰱��������β��ɣ�������ˮҹ���ᡱ
���⾳��
LONG);
	set("exits",([ /* sizeof() == 1 */
		"enter" : __DIR__"wave", 
		"east"  : __DIR__"wave1", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31020);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

