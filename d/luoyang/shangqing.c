// Room: /d/luoyang/shangqing.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "���幬");
	set("long",  @LONG
���幬λ����ɽ֮�۴��Ʒ壬�ഫ����Ϊ̫���Ͼ������������幬
��ģ��ΰ������Ρ�룬������ʯʨʯ�������ξ�ʮ���꣬��ʿ����ļ
Ǯ�ؽ�����ɽ�߷�󣬸ĵС��Ϊ�������ߣ��ݼ������ߣ��ʳƴ��
Ϊ�����������������ī������ɽ�ۣ���������ƽԭ���Ŷ������۵ס�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southeast" : __DIR__"mangshan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -510);
	set("coor/y", 60);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
