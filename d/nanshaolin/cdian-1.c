// Room: /d/nanshaolin/cdian-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ����Լ�
һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ��ȡ������˴���
���ɵ��Ӵ�������֮������λ����ɮ���������붨���������ĵ�������
����
LONG);
	set("exits", ([
		"west" : __DIR__"gchang-3",
	]));
	set("objects",([
		WEAPON_DIR+"stick/mugun" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

