// Room: /d/tiezhang/bqshi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ư��������Ʒ����Ṧ���ƣ��������Դ��д����ı������Թ���
�������İ���ʹ�á������������еĶ��Ǳ����ܣ������浶��ǹ������
ꪡ������ᡢ������Ӧ�о��С�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 4 */
		WEAPON_DIR+"gangdao" : 1,
		WEAPON_DIR+"gangjian" : 1,
		WEAPON_DIR+"gangzhang" : 1,
		WEAPON_DIR+"changbian" : 1,
		WEAPON_DIR+"spear/changqiang" : 1,
		WEAPON_DIR+"spear/muqiang" : 1,
		WEAPON_DIR+"spear/tieqiang" : 1,
	]));

	set("coor/x", -2030);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




