// spclone.c
// Write by Spacenet@FXLT 1.11.Y2k

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string file, err, msg;
	int count = 1, i;

	seteuid( geteuid(me) );

	if (!arg)
		file = me->query("cwf");
	else if (sscanf(arg, "%s %d", file, count) != 2)
		if (sscanf(arg, "%s", file) != 1)
			return notify_fail("��Ҫ����ʲô��\n");
	
	if (sscanf(file, "%*s.c") != 1)
		file += ".c";
		
	file = resolve_path(me->query("cwd"), file);
	me->set("cwf", file);

	if( file_size(file) < 0 )
		return notify_fail("û���������(" + file + ")��\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}
        
	err = catch(obj = new(file));
	if (err) {
		write("����ʧ�ܣ�" + err + "\n");
		return 1;
	}
	
	if( !stringp(msg = me->query("env/msg_clone")) )
		msg = sprintf("ֻ��$N�������һָ�������%s$n��\n", obj->query("money_id")?"һЩ":chinese_number(count) + obj->query("unit"));
	
	if ( !obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "���Ƴɹ�\�����������Ʒ����\n");
        	message_vision(msg + "\n", me, obj);
        	for (i = 0; i < count -1; i ++) {
			obj = new(file);
			obj->move(me);
		}
		return 1;
        }
        
	if( obj->move(environment(me)) && i == 0 ) {
		write(obj->query("name") + "���Ƴɹ�\������������䡣\n");
        	message_vision(msg + "\n", me, obj);
        	for (i = 0; i < count - 1; i ++) {
			obj = new(file);
			obj->move(environment(me));
		}
		return 1;
        }
        
	destruct(obj);
	return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int help(object me)
{
  write(@HELP
ָ���ʽ : spclone <�ļ���> [����]

���ô�ָ��ɸ����κ����ƶ�֮����(��NPC)�������ָ�����������ͬ��cloneָ�
HELP
    );
    return 1;
}

