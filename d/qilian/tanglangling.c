// Room: /d/qilian/tanglangling.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������ɽ����Ե�����������������������ƽԭ���������ţ�
�����������ء������ɽ��������ɽ�ƵͰ����ټ���ͨɽ���̣��ļ���
�䣬�ʶ�������
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastup"    : __DIR__"qitianfeng",
		"northdown" : "/d/xingxiu/jiayuguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
