// Room: /heizhao/hzneishi.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����ǽ��Χ��Բ�Σ���������ϸɳ��ɳ�ϻ�������ֱ���ź�
ԲȦ����д��Щ��̫��������Ԫ��������Ԫ��������Ԫ��������Ԫ
�����֡��㿴�ŵ��·��֣�����Щ�����е����⣬���㾭�еġ���
Ԫ֮������
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"hzneitang",
	]));
	set("coor/x", -5100);
	set("coor/y", -1470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}