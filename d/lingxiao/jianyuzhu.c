// Room: /d/lingxiao/jianyuzhu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "�η�");
	set("long", @LONG
�������һƬ����ϸϸ���������ñ�����ʯ�ŵķ�϶���Լ�ͷ��ȥ��
ʯ�ž�����ҡ�Σ���֪�ж���ʵ��һ����ɫ�԰׵������ˣ���ͷɥ����
���ڵ��ϡ�
LONG );
	set("exits", ([
		"west" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	])); 
	set("coor/x", -30980);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

