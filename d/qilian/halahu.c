// Room: /d/qilian/hamahu.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ˮ�����Ź��򶫣���ȥ�������֮Ϊ������������˵�ж���
�������棬ÿ�괺���������Է�ţ��ʮͷ�������ƽ������Ȼ��������
������ࡣ�����Ƿ�Բ�˰���Ψһ��ˮԴ��
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"yumen",
		"west"   : __DIR__"yumenguan",
	]));
	set("coor/x", -17000);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}