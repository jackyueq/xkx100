// Room: /d/wuyi/6qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
Ϫ����ɽ������Ϫˮ�峺���ף�ˮ�д����������Ӱ��ӡ��Ϫ
�׶���ʯ�ϣ������ž�Ө��ˮ��������������䣬���ͻأ�����䡶
�������衷Ի�����������������ı��壬��������ڲ�ء���������
�һ��䣬Գ�񲻾������С�������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"7qu",
		"southup"   : __DIR__"xiangshengyan",
		"southeast" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

