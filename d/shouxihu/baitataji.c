// Room: /yangzhou/baitataji.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
�������������Ų��������ڣ�һ�����������±�������������ʽ��
������׶�������Ʊ�������̨53����̨�������������пգ������ʰ
�����ϣ�����ͭӧ���̽����壬���ϴ��̽𶥡�ÿֵ���յ��գ�������
�����䣬���������ķ���ң����ţ���Ϊ���Ͼ޹ۡ���������С�����
��������׶��֮˵��
    ����������������̡���ʮ���Ρ�����ʮ����������̨��ʯ��ƽ̨
��Ƕ���������ơ�ʯ�
LONG );
	set("exits", ([
		"north" : __DIR__"lianxingsi",
		"up"    : __DIR__"baitafokan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}