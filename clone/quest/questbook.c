// quest_book.c �����鼮

inherit ITEM;

void dest_me()
{
	object env;
	env=environment(this_object());
	if (objectp(env) && !env->is_character())
	destruct(this_object());
}
void dest_me1()
{
	destruct(this_object());
}

void create()
{
	set_name("�����ؼ�", ({ "family book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬��ɫ�е��Ͼɡ�\n");
		set("value", 0);
		set("material", "paper");
	}
//	call_out("dest_me",500);//500������ʱ��
  call_out("dest_me1",1500);//1500������acceptʱ��
}
