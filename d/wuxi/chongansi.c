// Room: /d/wuxi/chongansi.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�簲��");
	set("long", @LONG
�������Ϲ�ɲ�����ڶ������꣬������˥������ս���ʢ��ÿ����
��ʮ�ţ����л�����Ϊ�����ķ��̼��̼����������У���ֺ��ӣ��ٷ�
Ԫ���ڣ����ﻹ�շű���ҹȼ�̻�ʮ�����֡����ٵõ���ɮ�����
�������֣��ŷ�Ҳ�ڴ��γɹ�Լ�����ڲ��ô�ܶ�Ź�����Ǵ�
LONG );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"enter"  : __DIR__"chongandadian",
		"west"   : __DIR__"northroad1",
	]));
	set("coor/x", 380);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}