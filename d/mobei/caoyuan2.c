// Room: /d/mobei/caoyuan2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
���������Į����ԭ����Ⱥ��ţ��İ����±��ܣ����ſ��������
�˻��������еĳ��ޣ������Ĳ�ԭ���ϱ�ȥ�ǵ���ԭ�������ȥ������
ľ���Ӫ�ʡ�
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"caoyuan3",
		"north"     : __DIR__"caoyuan",
	]));
	set("coor/x", -230);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
