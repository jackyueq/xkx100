// Room: /yangzhou/baitabaosha.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������ɲ");
	set("long",@LONG
Բ׶�ΰ�����ɲ���ɷ��ʮ����������ɣ��㼶�߶��ɣ�������
ɲ���������α��ǣ��Ƕ����ҷ��壬ÿ�������������󡣱���Ϊ��ͭ
ӧ�磬�����̽��ͭ�пպ�«�α���������������
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"down" : __DIR__"baitafokan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}