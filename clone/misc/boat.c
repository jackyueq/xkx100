// Room: /d/nanyang/duchuan.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳ�
����ݣ����ڴ�β�����س��Ŵ���
LONG );
	set("no_clean_up", 0);
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
