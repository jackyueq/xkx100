// Room: /d/lingxiao/dilao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������ڼ����������棬��ȴ�е���������͸�롣�����м䣬һ
����Ӱ�ֳ���������Ȼվ��ʯ���ԡ��չ�͸��������ֻ��������������
���ӣ���Ŀ��࣬����΢�����������ССʯ��װ�����������������
�ģ��۹�ҫ�����磬������ٱ�� 
LONG );
	set("exits", ([
		"out" : __DIR__"didi",
	]));
	set("objects", ([ 
		CLASS_D("lingxiao")+"/bai" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 120);
	setup(); 
	replace_program(ROOM);
}

