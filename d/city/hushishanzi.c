// Room: /city/hushishanzi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "��ʯɽ��");
	set("long", @LONG
��ʯɽ�Ӻ�ب��Ժ�䵱�У�����¥�����������ӡ�ɽ����ʯ��������
ɽ���ж������ػء����������Ƥ��ֲ��ɽ�룬֦��������������ȥ
�����ţ�ʯ���������ۣ���¥����麣�¥����ˮ������
LONG );
	set("exits", ([
		"west"       : __DIR__"shufengguan",
		"southwest"  : __DIR__"meichuanxuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -47);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}