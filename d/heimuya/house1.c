// Room: /d/heimuya/house1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����һ�����ŵ�С�ᣬһ���ű���ŵ�һ��Ũ���Ļ��㡣���й���
һ����Ů���ͼ��ͼ�л��������װ��Ů����Ŀ���⣬�������ס�����
����һ�Ų輸���������ӣ������������廨���棬������һ�ȶ�����ͨ
�������
LONG );

	set("exits",([
		"west"  : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
