// Room: /d/mobei/chulan.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ķֳɼ��񣬷ֱ�Ȧ�˼�ͷţ��һ�ߵ�ľ׮�ϣ���ϵ����
ƥ��Ȧ���в�ʱ����ţ��Ľ����������˻��һ���Ǽ�����õ�
Сé���ݡ��ſڣ������ж���ɨ�úܸɾ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"byriver",
	]));
	set("outdoors","mobei");
	set("coor/x", -190);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
