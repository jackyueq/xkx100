// Room: /d/nanyang/wuhouci.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
�������Ϊ����ʱ�ڵ������������������������������ഫ��
�Ｔ�����ļ��硣����ɽ�ţ������ɰ�ɭɭ�������ľ���Ժ������һ��
����ͤ���ʻ����ܣ���ƾ��ɡ�����ֱ���С�ɵ��ӣ���¥���໥��Ӧ
�����������
LONG);
	set("exits",([
		"southwest" : __DIR__"dajie2",
		"north"     : __DIR__"zhengdian",
	]));
	set("outdoors","nanyang");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
