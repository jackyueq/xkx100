//Room: /d/dali/changhu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�������ܳ�Լʮ�������������Σ������������ܵĴ����С�
������һ�����£��������л�ҫ�������ɰس��֣��Դ����Σ�������
�£�ɫ��Ҷ�ۣ�����ɽ������׺��䡣��ˮ���̣���һ����΢���ж�
���Ľ��У��̵ľ�Ө���̵Ļ�Ծ���̵����ˡ�
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "southdown"  : __DIR__"shilin",
	    "west"       : __DIR__"shilin1",
	    "northeast"  : __DIR__"shilin2",
	    "enter"      : __DIR__"hole",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -54000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}