// yahuan.c Ѿ��

inherit NPC;
void create()
{
	set_name( "Ѿ��", ({ "ya huan", "yahuan" }) );
	set( "title", "�" );
	set( "attribute", "peaceful" );
	set( "gender", "Ů��" );
	set( "age", 15 );
	set( "long", @LONG
һ��Ѿ�ߣ�����С�ɿɰ���ԲԲ�����ϴ�Ц�����㡣
LONG);
    
	set( "str", 20 );
	set( "dex", 20 );
	set( "per", 22 );
	set( "combat_exp", 1000 );
    
	set( "inquiry", ([
        "�" : "�������㲻�������\n",
        "С����ɽ��" : "�������\n",
        "����" : "���ݷ��������£�\n",
        "����ʯ" : "�����Ҽ���ү��\n"
	]) );
    
	set("chat_chance", 20);
	set("chat_msg", ({
        "��ү˵����������İ���˴�ǻ�ġ�",
        "СŮ�����£��Բ����ˡ�",
    }) );
	setup();
	carry_object(__DIR__"obj/pink_cloth" )->wear();
	carry_object(__DIR__"obj/flower_shoe" )->wear();
}
