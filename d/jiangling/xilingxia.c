//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
  set ("short", "����Ͽ");
  set ("long", @LONG
����������ʯ��ᾣ�����������Գ�����ʡ�̲���������ԡ��ա���
�����ԡ��桱���ƣ����桱�����ա���Ϊ׳��������Ͽ����Ͽ����Ͽ��
СϿ��̲����̲����̲��С̲��չ��������ǰ����ɫ�ʰ�����������ǧ
��׳��������������������Ͽ��������һƬ��ʯ�ԡ�
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"wuxia",
		"north": __DIR__"shangang2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
