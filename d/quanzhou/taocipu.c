// Room: /d/quanzhou/taocipu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�մ���");
	set("long", @LONG
�������Ƹ�ʽ�������մ���Ʒ����̨�ϰ��Ż�ɫ��������ƿ�ޣ�
���͸�����ɶ��칤�����������ϸ��Բ������������������������
��λ���������ͼ����������Ǵ��Ӳ���Ů��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"xinmenji",
	]));
	set("coor/x", 1840);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
