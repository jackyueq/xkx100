// /d/meizhuang/xiuxishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
������÷ׯ�����������۵�ʱ����Ϣ�ĵط������ﾭ����������
���׵�����������򵥵ķ��ż��ŵ��ӣ������ޱ���������ͷ������÷
ׯ������Ȼ������ɨ�����������Ȼ���Ҳ������ܶ�÷ׯ����һ����
���ͷ��˯�����ǹ���ƣ�͵�Ե�ʡ� 
LONG
	);
	set("sleep_room", "yes");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"zoulang2",
	]));
	set("no_fight", "yes");
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
